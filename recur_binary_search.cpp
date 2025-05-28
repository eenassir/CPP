#include <iostream>
#include <vector>

void search(std::vector<int> & vect, int key)
{
    if (vect[(vect.size() / 2)] == key)
    {
        std::cout <<"the key is founded in the list"<<std::endl;
        return ;
    }
    if (vect.size() <= 1)
    {
        std::cout <<"the key didn't founded in the list"<<std::endl;
        return ;
    }
    std::vector<int> k;
    size_t size = vect.size() / 2, i = 0;
    while (i < size)
    {
        k.push_back(vect.back());
        vect.pop_back();
        i++;
    }
    search(k, key);
    search(vect, key);
    std::vector<int>::iterator it;

    it = k.end();
    it--;
    while (it != (k.begin() - 1))
    {
        vect.push_back(k.back());
        k.pop_back();
        it--;
    }
}

int main()
{
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(7);
    vect.push_back(8);

    search(vect, 0);
}