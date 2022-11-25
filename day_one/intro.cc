#include<iostream>
#include<vector>


template<typename number>
void print_vector(std::vector<number>&array)
{
    for(number&n:array)
    {
        std::cout<<n<<' ';
    }
    std::cout<<'\n';
}

// bad, boo doing repeated work. we can just remove left-most number from sum then advance left pointer then advance right
//poiner and add it to sum
std::vector<double>k_average(std::vector<int>&&array,int&&k)
{
    std::vector<double>averages;
    double s{0};
    size_t R{0};
    for(size_t L{0};R<array.size()-1;++L)
    {
        s=0;
        R=(L+k)-1;
        for(size_t i{L};i <= R; ++i)
        {
            s+=(double)array[i];
        }
        averages.push_back(s/k);
    }
    return averages;
}

std::vector<double>k_average1(std::vector<int>&&arr,int&&k)
{
    std::vector<double>averages;
    double s{0};
    size_t R{0},L{0};
    for(;R<k;++R)
    {
        s+=(double)arr[R];
    }
    for(R=R-1;R<arr.size();++L)
    {
        averages.push_back(s/k);
        s-=arr[L];
        s+=arr[++R];
    }
    return averages;
}


int main()
{
    std::vector<double>v=k_average1({1,3,2,6,-1,4,1,8,2},5);
    print_vector(v);
    return 0;
}
