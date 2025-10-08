#ifndef TILE_H
#define TILE_H

class Tile
{
public:
    Tile() = default;
    explicit Tile(int num);
    bool isEmpty() const;
    int getNum() const;
    friend std::ostream& operator<<(std::ostream& out, Tile& t);

private:
    int m_num {};
};

#endif
