#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE T4 DONE
    ////

    // data handles (owned)
    std::vector<std::shared_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge*> _parentEdges; // edges to preceding nodes 

    // change it to smart pointer so that i have to do less work
    ChatBot *_chatBot;
    //std::shared_ptr<ChatBot> _chatBot; // shared for copying

    ////
    //// EOF STUDENT CODE T4 DONE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(GraphEdge *edge);

    //// STUDENT CODE T5
    ////

    void MoveChatbotHere(ChatBot *chatbot);

    ////
    //// EOF STUDENT CODE T5

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */