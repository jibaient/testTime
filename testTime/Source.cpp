#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

int main()
{
    std::vector<double> L;
    for (auto i = 0; i < 1000; i++)
    {
        using namespace std::chrono_literals;
        auto start = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(10ms);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << elapsed.count() << " ms\n";
        L.push_back(elapsed.count());
    }
    
    double min = 11;
    double max = 10;

    for (auto element : L)
    {
        if (element<min)
        {
            min = element;
        }

        if (element>max)
        {
            max = element;
        }
    }

    std::cout << min << " " << max << std::endl;
}