#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "DataManager.h"
#include "DataPacket.h"
#include "MACD.h"

using namespace std;

int main(){
    try {
        MACD<double> macd(6,12);

        DataManager<double> dm;
        dm += &macd;

        std::chrono::milliseconds timespan(1000); // or whatever

        DataPacket<double> p;
        p.utc_timestamp = time(0);
        p.open = rand()%35+15;
        p.high = rand()%35+25;
        p.low = rand()%15+1;
        p.close = rand()%50+30;
        p.volume = rand()%35+15;

        //simulate up trend
        for(int i = 0; i < 30; i++){
            DataPacket<double> packet(p);
            packet.utc_timestamp = time(0);
            packet.open += rand()%3;
            packet.high += rand()%3;
            packet.low += rand()%3;
            packet.close += rand()%3;
            packet.volume += rand()%3;

            p = packet;

            packet.display();
            dm.dataChange(packet);
            std::this_thread::sleep_for(timespan);

            cout << endl;
        }

        //simulate down trend
        for(int i = 0; i < 30; i++){
            DataPacket<double> packet(p);
            packet.utc_timestamp = time(0);
            packet.open -= rand()%3;
            packet.high -= rand()%3;
            packet.low -= rand()%3;
            packet.close -= rand()%3;
            packet.volume -= rand()%3;

            p = packet;
            
            dm.dataChange(packet);
            std::this_thread::sleep_for(timespan);

            cout << endl;
        }
    }
    catch (const std::out_of_range& oor) {
        std::cerr << oor.what() << '\n';
    }

    return 0;
}