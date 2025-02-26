#include"class.h"
#include <string>
#include <utility>
Position::Position():x(0), y(0) {
    this->setDefaultMessage();
}
Position::Position(int x, int y): x(x), y(y) {
    this->setDefaultMessage();
}
Position::Position(int x, int y, std::string message):
x(x), y(y), message(message) {
    //
}
Position::~Position() {
    //
}
void Position::setDefaultMessage() {
    this->message = "Position (" + std::to_string(this->x) + std::to_string(this->y) + ")";
}
int Position::getX() const {
    return this->x;
}
int Position::getY() const {
    return this->y;
}
std::pair<int, int> Position::getXY() const {
    return {this->x, this->y};
}
std::string Position::getMessage() const{
    return this->message;
}
void Position::setX(int x) {
    this->x = x;
    this->setDefaultMessage();
}
void Position::setY(int y) {
    this->y = y;
    this->setDefaultMessage();
}
void Position::setMessage(std::string message) {
    this->message = message;
}