
#include <bits/stdc++.h>

using namespace std;

class DocumentPart{
private:
    string name;
    pair<int, int> position;
public:
    virtual void paint() = 0;
    virtual void save() = 0;
}
class WordDocument{
private:
    vector<DocumentPart*> partList;
public:
    void open();
    void save();
};
void WordDocument::open(){
    for(auto docPart: partList){
        docPart->paint();
    }
}
void WordDocument::save(){
    for(auto docPart: partList){
        docPart->save();
    }
}

class Header : public DocumentPart{
    string title;
    void paint(){
        // display element
    }
    void save(){
        // save element
    }
};
class Footer : public DocumentPart{
    string text;
    void paint(){
        // display element
    }
    void save(){
        // save element
    }
};
class Paragraph : public DocumentPart{
    string content;
    int lines;
    void paint(){
        // display element
    }
    void save(){
        // save element
    }
};
class Hyperlink : public DocumentPart{
    string link;
    void paint(){
        // display element
    }
    void save(){
        // save element
    }
};


int main()
{
    cout<<"Hello World";

    return 0;
}
