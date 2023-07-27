#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE T5 DONE
    ////

    // shared ptr
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE T5 DONE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    std::shared_ptr<GraphEdge> nextEdge(edge);
    _childEdges.push_back(nextEdge);
}

//// STUDENT CODE T5 DONE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    //std::shared_ptr<ChatBot> chatBot = std::make_shared<ChatBot>(std::move(*chatbot)); // looks kinda ugly but idk
    ChatBot chatBot = ChatBot();
    if(chatbot && chatbot != nullptr){
        //chatBot = std::move(*chatbot);
    }
    //_chatBot = new ChatBot(chatBot);
    _chatBot = std::move(chatbot);
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); 
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE T5 DONE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE T4 DONE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE T4 DONE
}