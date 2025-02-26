#include<string>
class Position {
    private:
        int x;
        int y;
        std::string message;
        void setDefaultMessage(); 
    public:
        Position();
        Position(int x, int y);
        Position(int x, int y, std::string message);
        ~Position();
        int getX() const;
        int getY() const;
        std::pair<int, int> getXY() const;
        std::string getMessage() const;
        void setX(int x);
        void setY(int y);
        void setMessage(std::string message);
};