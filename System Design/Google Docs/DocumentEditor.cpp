#include <bits/stdc++.h>
using namespace std;

// Abstraction for document elements
class DocumentElement{
public:
    virtual string render() = 0;
};

// Concrete implementation of text elements
class TextElement: public DocumentElement{
private:
    string text;

public:
    TextElement(string text){
        this -> text = text;
    }

    string render() override{
        return text;
    }
};

class ImageElement: public DocumentElement{
private:
    string path;
public:
    ImageElement(string path){
        this -> path = path;
    }

    string render() override{ 
        return "[Image: " + path + "]";
    }
};

class NewLineElement: public DocumentElement{
public:
    string render() override{
        return "\n";
    }
};

class TabSpaceElement: public DocumentElement{
public:
    string render() override{
        return "\t";
    }
};

class Document{
private:
    vector<DocumentElement*> documentElements;

public:
    void addElement(DocumentElement* elem){
        documentElements.push_back(elem);
    }

    string render(){
        string result;

        for(auto elem : documentElements){
            result += elem -> render();
        }

        return result;
    }
};

class Percistence{
public:
    virtual void save(string data) = 0;
};

class FileStorage: public Percistence{
public:
    void save(string data) override{
        ofstream outFile("document.txt");

        if(outFile){
            outFile << data;
            outFile.close();
            cout<<"Document saved to document.txt" << endl;
        }
        else{
            cout<<"Error: Unable to open file for writing." << endl;
        }
    }
};

class DBStorage: public Percistence{
public:
    void save(string data) override{
        cout<<"Document saved to database." << endl;
    }
};

class DocumentEditor{
private:
    Document* document;
    Percistence* storage;
    string renderedDocument;

public:
    DocumentEditor(Document* document, Percistence* storage){
        this -> document = document;
        this -> storage = storage;
    }

    void addText(string text){
        document -> addElement(new TextElement(text));
    }

    void addImage(string path){
        document -> addElement(new ImageElement(path));
    }

    void addNewLine(){
        document -> addElement(new NewLineElement());
    }

    void addTabSpace(){
        document -> addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document -> render();
        }
        return renderedDocument;
    }

    void saveDocument(){
        storage -> save(renderDocument());
    }
};

int main(){
    Document* document = new Document();
    Percistence* percistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, percistence);

    // Simulate a client using the editor
    editor -> addText("Hello, World!");
    editor -> addNewLine();
    editor -> addText("This is a real world editor example.");
    editor -> addNewLine();
    editor -> addTabSpace();
    editor -> addText("Indented Text after a tab space.");
    editor -> addNewLine();
    editor -> addImage("image.jpg");

    // Render and display the final document
    cout<<editor -> renderDocument() << endl;

    editor -> saveDocument();

    return 0;
}