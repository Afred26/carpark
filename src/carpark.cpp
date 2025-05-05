#include "carpark.h"

CarPark::CarPark(std::vector<std::vector<std::string>> const &ids)
{
    for (int i = 0; i < ids.size(); i++)
    {
        carpark.push_back({});
        for (int t = 0; t < ids[i].size(); t++)
        {
            carpark[i].insert({ids[i][t], false});
        }
    }
}

bool CarPark::hasId(size_t deck_no, std::string const &id) const
{
    auto result = carpark.at(deck_no).find(id);
    if (result == carpark.at(deck_no).end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool CarPark::isOccupied(size_t deck_no, std::string const &id) const
{
    if (!hasId(deck_no, id))
    {
        return true;
    }
    else
    {
        return carpark.at(deck_no).at(id);
    }
}

bool CarPark::occupy(size_t deck_no, std::string const &id)
{
    if (!hasId(deck_no, id) || carpark.at(deck_no).at(id))
    {
        return false;
    }
    else
    {
        carpark.at(deck_no).at(id) = true;
        return true;
    }
}

bool CarPark::release(size_t deck_no, std::string const &id)
{
    if (!carpark.at(deck_no).at(id) || !hasId(deck_no, id))
    {
        return false;
    }
    else
    {
        carpark.at(deck_no).at(id) = false;
        return true;
    }
}

size_t CarPark::vacant() const
{
    int count = 0;
    for (int i = 0; i < carpark.size(); i++)
    {
        for (auto &[id, besetzt] : carpark.at(i))
        {
            if (!besetzt)
            {
                count++;
            }
        }
    }
    return count;
}

size_t CarPark::occupied() const
{
    int count = 0;
    for (int i = 0; i < carpark.size(); i++)
    {
        for (auto &[id, besetzt] : carpark.at(i))
        {
            if (besetzt)
            {
                count++;
            }
        }
    }
    return count;
}

size_t CarPark::size() const
{
    int count = 0;
    for (int i = 0; i < carpark.size(); i++)
    {
        count += carpark[i].size();
    }
    return count;
}

int CarPark::parkingFee() const
{
    return (size() - vacant());
}
