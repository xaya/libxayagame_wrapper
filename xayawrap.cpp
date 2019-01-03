#define XAYAWRAP_API __declspec(dllexport) __stdcall

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <csetjmp>
#include <csignal>

#include "xayagame/defaultmain.hpp"
#include "xayagame/gamelogic.hpp"

#include <json/json.h>
#include <jsonrpccpp/client.h>

#include <glog/logging.h>

typedef const char* (*INITIAL_CALLBACK)(unsigned&, const char**);
typedef const char* (*FORWARD_CALLBACK)(const char*, const char*, const char*, const char**);
typedef const char* (*BACKWARD_CALLBACK)(const char*, const char*, const char*);

static INITIAL_CALLBACK initialCallback;
static FORWARD_CALLBACK forwardCallback;
static BACKWARD_CALLBACK backwardCallback;

static xaya::GameLogicCallbacks callbackStruct;
static xaya::Chain chain;

static Json::StreamWriterBuilder jsonWriterBuilder;
static int sChain;
static int sPort;

/* This is needed to workaround Unity crash
on abort signal;*/
jmp_buf env;

void
on_sigabrt(int signum)
{
  longjmp(env, 1);
}

xaya::GameStateData
initial(xaya::Chain chain, unsigned& height, std::string& hashHex)
{

  const char* hashHexFill;
  unsigned heightS;
  
  initialCallback(heightS, &hashHexFill);
  
  std::string newStateString;
  (&hashHex)->assign(hashHexFill);    
  
  height = heightS;
  
  return "";
}

xaya::GameStateData
forward(xaya::Chain chain, const xaya::GameStateData& oldState,
        const Json::Value& blockData, xaya::UndoData& undoData)
{
  const char* newState;
  const std::string blockDataStr =
    Json::writeString(jsonWriterBuilder, blockData);
  const char* result =
    forwardCallback(oldState.c_str(), blockDataStr.c_str(), undoData.c_str(), &newState);
  std::string resultString;
  
  (&resultString)->assign(result);
  std::string newStateString;
  
  (&newStateString)->assign(newState);  
  undoData = resultString;
  return newStateString;
}

xaya::GameStateData
backward(xaya::Chain chain, const xaya::GameStateData& newState,
         const Json::Value& blockData, const xaya::UndoData& undoData)
{
  const std::string blockDataStr =
    Json::writeString(jsonWriterBuilder, blockData);
  const std::string newDataStr = Json::writeString(jsonWriterBuilder, newState);
  return backwardCallback(newDataStr.c_str(), blockDataStr.c_str(),
                          undoData.c_str());
}

int
ConnectToTheDaemon(std::string gameId, std::string XayaRpcUrl, int GameRpcPort,
                   int EnablePruning, int chain, std::string storageType,
                   std::string dataDirectory, std::string glogName,
                   std::string glogDataDir)
{

  sPort = GameRpcPort;
  sChain = chain;

  FLAGS_alsologtostderr = 1;
  FLAGS_log_dir = glogDataDir;

  google::InitGoogleLogging(glogName.c_str());

  xaya::GameDaemonConfiguration config;
  config.XayaRpcUrl = XayaRpcUrl;
  config.GameRpcPort = GameRpcPort;
  config.GameRpcServer = xaya::RpcServerType::TCP;
  config.EnablePruning = EnablePruning;

  config.StorageType = storageType;
  config.DataDirectory = dataDirectory;

  jsonWriterBuilder["commentStyle"] = "None";
  jsonWriterBuilder["enableYAMLCompatibility"] = false;
  jsonWriterBuilder["indentation"] = "";

  callbackStruct.GetInitialState = initial;
  callbackStruct.ProcessForward = forward;
  callbackStruct.ProcessBackwards = backward;

  LOG(WARNING) << "gameId: " << gameId;
  LOG(WARNING) << "XayaRpcUrl: " << XayaRpcUrl;
  LOG(WARNING) << "GameRpcPort: " << GameRpcPort;
  LOG(WARNING) << "EnablePruning: " << EnablePruning;
  LOG(WARNING) << "chain: " << chain;
  LOG(WARNING) << "storageType: " << storageType;
  LOG(WARNING) << "dataDirectory: " << dataDirectory;
  LOG(WARNING) << "glogName: " << glogName;
  LOG(WARNING) << "glogDataDir: " << glogDataDir;

  if (setjmp(env) == 0) {
    signal(SIGABRT, &on_sigabrt);
    int dd = xaya::DefaultMain(config, gameId, callbackStruct);
  } else {
  }

  google::ShutdownGoogleLogging(); // Adding this mandatory, took so long to
                                   // figure out V____V
                                   // >____>  <____<
  return 0;
}

extern "C" 
{
	
XAYAWRAP_API void
setInitialCallback(INITIAL_CALLBACK callback)
{
  if (callback) {
    initialCallback = callback;
  }
}

XAYAWRAP_API void
setForwardCallback(FORWARD_CALLBACK callback)
{
  if (callback) {
    forwardCallback = callback;
  }
}

XAYAWRAP_API void
setBackwardCallback(BACKWARD_CALLBACK callback)
{
  if (callback) {
    backwardCallback = callback;
  }
}

XAYAWRAP_API int
CSharp_ConnectToTheDaemon(char* jarg1, char* jarg2, int jarg3, int jarg4,
                          int jarg5, char* jarg7, char* jarg8, char* jarg9,
                          char* jarg10)
{
  int jresult;
  std::string arg1;
  std::string arg2;
  std::string arg7;
  std::string arg8;
  std::string arg9;
  std::string arg10;
  int arg3;
  int arg4;
  int arg5;
  int arg6;
  int result;

  (&arg1)->assign(jarg1);
  (&arg2)->assign(jarg2);
  (&arg7)->assign(jarg7);
  (&arg8)->assign(jarg8);
  (&arg9)->assign(jarg9);
  (&arg10)->assign(jarg10);

  arg3 = (int)jarg3;
  arg4 = (int)jarg4;
  arg5 = (int)jarg5;

  result = (int)ConnectToTheDaemon(arg1, arg2, arg3, arg4, arg5, arg7, arg8,
                                   arg9, arg10);

  jresult = result;
  return jresult;
}
}
