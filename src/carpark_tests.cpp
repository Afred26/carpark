#include <catch2/catch_test_macros.hpp>

#include "carpark.h"

using namespace std;

TEST_CASE("Konstruktor", "[CarPark]")
{
    vector<string> ids_deck_a{"A01", "A02", "A03"};
    vector<string> ids_deck_b{"B01", "B02", "B03"};
    vector<string> ids_deck_c{"C01", "C02", "C03"};

    CarPark cp({ids_deck_a, ids_deck_b, ids_deck_c});

    REQUIRE(cp.size() == 9);
    REQUIRE(cp.occupied() == 0);
    REQUIRE(cp.vacant() == 9);
    REQUIRE(cp.parkingFee() == 0);
}

TEST_CASE("has_id", "[CarPark]")
{
    vector<string> ids_deck_a{"A01", "A02", "A03"};
    vector<string> ids_deck_b{"B01", "B02", "B03"};
    vector<string> ids_deck_c{"C01", "C02", "C03"};

    CarPark cp({ids_deck_a, ids_deck_b, ids_deck_c});

    REQUIRE(cp.hasId(0, "A01") == true);
    REQUIRE(cp.hasId(1, "B01") == true);
    REQUIRE(cp.hasId(2, "C01") == true);
    REQUIRE(cp.hasId(0, "B01") == false);
}

TEST_CASE("is_occupied", "[CarPark]")
{
    vector<string> ids_deck_a{"A01", "A02", "A03"};
    vector<string> ids_deck_b{"B01", "B02", "B03"};
    vector<string> ids_deck_c{"C01", "C02", "C03"};

    CarPark cp({ids_deck_a, ids_deck_b, ids_deck_c});

    REQUIRE(cp.isOccupied(0, "A01") == false);
    REQUIRE(cp.isOccupied(1, "B01") == false);
    REQUIRE(cp.isOccupied(2, "C01") == false);
    REQUIRE(cp.isOccupied(0, "B01") == true);
}

TEST_CASE("occupy", "[CarPark]")
{
    vector<string> ids_deck_a{"A01", "A02", "A03"};
    vector<string> ids_deck_b{"B01", "B02", "B03"};
    vector<string> ids_deck_c{"C01", "C02", "C03"};

    CarPark cp({ids_deck_a, ids_deck_b, ids_deck_c});

    REQUIRE(cp.vacant() == 9);
    REQUIRE(cp.parkingFee() == 0);
    REQUIRE(cp.isOccupied(0, "A01") == false);
    REQUIRE(cp.occupy(0, "A01") == true);
    REQUIRE(cp.isOccupied(0, "A01") == true);
    REQUIRE(cp.vacant() == 8);
    REQUIRE(cp.parkingFee() == 1);

    REQUIRE(cp.isOccupied(0, "B01") == true);
    REQUIRE(cp.occupy(0, "B01") == false);
    REQUIRE(cp.isOccupied(0, "B01") == true);
}

TEST_CASE("release", "[CarPark]")
{
    vector<string> ids_deck_a{"A01", "A02", "A03"};
    vector<string> ids_deck_b{"B01", "B02", "B03"};
    vector<string> ids_deck_c{"C01", "C02", "C03"};

    CarPark cp({ids_deck_a, ids_deck_b, ids_deck_c});

    cp.occupy(0, "A01");

    REQUIRE(cp.vacant() == 8);
    REQUIRE(cp.parkingFee() == 1);
    REQUIRE(cp.isOccupied(0, "A01") == true);
    REQUIRE(cp.release(0, "A01") == true);
    REQUIRE(cp.isOccupied(0, "A01") == false);
    REQUIRE(cp.vacant() == 9);
    REQUIRE(cp.parkingFee() == 0);
}
