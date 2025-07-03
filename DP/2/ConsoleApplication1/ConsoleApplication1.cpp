#include <string>
#include <iostream>
#include <algorithm> 
using namespace std;

class Text 
{
    public:
        virtual void render(const std::string& data) const 
        {
            cout << data;
        }
};

class DecoratedText : public Text 
{
    public:
         explicit DecoratedText(Text* text) : text_(text) {}
         Text* text_;
};

class ItalicText : public DecoratedText 
{
    public:
         explicit ItalicText(Text* text) : DecoratedText(text) {}
         void render(const std::string& data)  const 
         {
              cout << "<i>";
              text_->render(data);
              cout << "</i>";
         }
};

class BoldText : public DecoratedText 
{
    public:
        explicit BoldText(Text* text) : DecoratedText(text) {}
        void render(const std::string& data) const 
        {
            cout << "<b>";
            text_->render(data);
            cout << "</b>";
        }
};

class Paragraph : public Text       // класс параграф
{
public:
    explicit Paragraph(Text* text) : text_(text) {}   

    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        cout << "</p>" << endl;
    }
private:
    Text* text_;
};

class Reversed : public Text                 // класс разворота строки
{
public:
    explicit Reversed(Text* text) : text_(text) {}   
    void render(const std::string& data) const override 
    {
        string reversed_data = data;
        reverse(reversed_data.begin(), reversed_data.end());
        text_->render(reversed_data);
        cout << endl;
    }   
private:
    Text* text_;
};

class Link : public Text            //класс Link с другой сигнатурой
{
public:
    explicit Link(Text* text) : text_(text) {}  
   
    void render(const std::string& url, const std::string& data) const   // другой метод
    {
        cout << "<a href=" << url << ">";
        text_->render(data);
        cout << "</a>" << endl;
    }
   
    void render(const std::string& data) const override          // реализация метода
    {
        text_->render(data);
    }
private:
    Text* text_;
};

int main() 
{
    //проверяем
    auto text_block = new Paragraph(new Text());
    text_block->render("Hello world");
    delete text_block;

    auto text_block1 = new Reversed(new Text());
    text_block1->render("Hello world");
    delete text_block1;
       
    auto text_block2 = new Link(new Text());
    text_block2->render("netology.ru", "Hello world");
    delete text_block2;
  
}