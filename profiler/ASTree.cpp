//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2022 Kent State University. All rights reserved.
//  Fall 2022
//  srcML 1.0
//
//  Modified by: Jason Graham
//
//

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree = new AST(*(actual.tree));
    else
        tree = 0;
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    //TODO: IMPLEMENT
    if(!child.empty()) {
        std::list<AST*>::iterator ptr = child.begin();
        while(ptr != child.end()) {
            delete *ptr;
            ++ptr;
        }
    }
    //Recursively traverse tree and delete from bottom up
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) : AST() {
    //TODO: IMPLEMENT
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;
    if(actual.child.empty()) return;
    for(std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i) {
        child.push_back(new AST(**i)); // This line may be wrong if anything is
    }


    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    AST temp(rhs);

    //Swap basic data
    rhs.nodeType = nodeType;
    rhs.tag      = tag;
    rhs.closeTag = closeTag;
    rhs.text     = text;
    nodeType     = temp.nodeType;
    tag          = temp.tag;
    closeTag     = temp.closeTag;
    text         = temp.text;

    //Swap tree structure
    rhs.child = child;
    child = temp.child;
    //Swap all the top level childern (pointers to AST)
}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) {

    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"

    //Quick explanation of findings
    //Top level AST contains a list of all things within the file, functions and comments
    //every other pointer is an account of the whitespace between readable lines
    //Traversing is difficult

    //Goal is to find main... back step by one line
    //then insert the line(s) I need for main.cpp
    std::list<AST*>::iterator ptr = child.begin();
    //Find main function
    while((*ptr)->tag != "function" && ptr != child.end()) {++ptr; } // || (*ptr)->getChild("name")->getName() != "main"

    //Setup new token
    AST* include = new AST(token, "#include \"profile.hpp\"\n");
    child.insert(ptr, include);

    for(unsigned i = 0; i < profileName.size(); ++i) {
        include = new AST(token, ("profile " + profileName[i] + "(\"" + fileName[i] + "\");\n"));
        child.insert(ptr, include);
    }
    (*--ptr)->text += '\n';

    //---------------------------------------------------------------------
    //---------------------------------------------------------------------
    // All of the comments for the rest of this function is simply me
    // (Unneccessaraly) creating my own .XML AST to insert one line of text
    // (Supper over complicating the code)
    // and beneath that is me having fun learning how exactly the AST
    // data structure opperates




    
    //Construct the AST that will be inserted to main
    /*AST* temp = new AST(nodes(category), "cpp:include");
    temp->child.push_back(new AST(nodes(token), "#"));
    temp->child.push_back(new AST(nodes(category), "cpp:directive"));
        temp->child.back()->child.push_back(new AST(nodes(token), "include"));
    temp->child.push_back(new AST(nodes(whitespace), ))*/




    /*int i = 0;
    std::list<AST*>::iterator ptr = child.begin();
    while(ptr != child.end()) { // (*ptr)->getChild("function")->getName() != "main" && 

        std::cout << "i: " << i << ", ";

        if(i % 2 == 0) {
            std::cout << (*ptr)->tag << ", " << (*ptr)->nodeType << std::endl;
        } else {
            std::cout << (*ptr)->tag << ", " << (*ptr)->nodeType << std::endl;
        }

        if(i == 16) {
            std::cout << (*ptr)->child.size() << std::endl;
            std::cout << "-------------------------" << std::endl;
            int j = 0;
            std::list<AST*>::iterator include = (*ptr)->child.begin();
            while(include != (*ptr)->child.end()) {
                std::cout << "j: " << j << ", ";
                std::cout << (*include)->tag << ", " << (*include)->nodeType << std::endl;

                ++include;
                ++j;
            }
            std::cout << "-------------------------" << std::endl;
        }

        if((*ptr)->tag == "function") { // && (*ptr)->getChild("name")->text == "main"
            std::cout << "entered a function: " << (*ptr)->getChild("name")->getName() << std::endl;
        }

        std::cout << std::endl;

        ++ptr;
        ++i;
    }*/

    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"
}


//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {
    //TODO: IMPLEMENT
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"
    
    std::list<AST*>::iterator ptr = child.begin();
    //Find function
    while((*ptr)->tag != "function" && (*ptr)->tag != "constructor" && (*ptr)->tag != "destructor" && ptr != child.end()) {++ptr; }

    //Setup new token
    AST* include = new AST(token, "#include \"profile.hpp\"\n");
    child.insert(ptr, include);

    include = new AST(token, ("extern profile " + profileName + ";\n"));
    child.insert(ptr, include);
    (*--ptr)->text += '\n';

}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //TODO: IMPLEMENT
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return
    //std::cout << foo_cpp << std::endl;

    std::list<AST*>::iterator ptr = child.begin();
    //Find main function
    while(((*ptr)->tag != "function" || (*ptr)->getChild("name")->getName() != "main") && ptr != child.end()) {++ptr; }
    //Set iterator to the end of block statement just before "}"
    std::list<AST*>::iterator blockptr = (*ptr)->getChild("block")->getChild("block_content")->child.end(); // "}"
    --blockptr;

    while((*blockptr)->tag != "return" && blockptr != (*ptr)->getChild("block")->getChild("block_content")->child.begin()) {--blockptr; }
    if(blockptr == (*ptr)->getChild("block")->getChild("block_content")->child.begin()) blockptr = --(*ptr)->getChild("block")->getChild("block_content")->child.end(); // incase of no return in main

    //Setup new tokens
    for(unsigned i = 0; i < profileName.size(); ++i) {
        (*ptr)->getChild("block")->getChild("block_content")->child.insert(blockptr, new AST(token, ("\nstd::cout << " + profileName[i] + " << std::endl;")));
    }
    (*--blockptr)->text += "\n\n";

}


// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");

    //Find function
    for(std::list<AST*>::iterator ptr = child.begin(); ptr != child.end(); ++ptr) {
        if((*ptr)->tag == "function" || (*ptr)->tag == "constructor" || (*ptr)->tag == "destructor") {

            child.insert(++((*ptr)->getChild("block")->child.begin()), new AST(token, " " + profileName + ".count(__LINE__, \"" + (*ptr)->getChild("name")->getName() + "\");"));

        }
    }
}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing

    //Find function
    for(std::list<AST*>::iterator ptr = child.begin(); ptr != child.end(); ++ptr) {
        //If it's a category and it's not included on the StopTag list then run
        if((*ptr)->nodeType == category && !isStopTag((*ptr)->tag)) {
            if((*ptr)->tag == "expr_stmt") {
                child.insert(++ptr, new AST(token, " " + profileName + ".count(__LINE__);"));

            } else if((*ptr)->tag == "condition") {
                child.insert((*ptr)->getChild("expr")->child.begin(), new AST(token, profileName + ".count(__LINE__), "));

            } else {
                (*ptr)->lineCount(profileName);

            }

        }

    }
    
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    //if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

