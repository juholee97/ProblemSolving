#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdint>

namespace ps16496
{
bool Compare( std::string lfs, std::string rfs )
{
    auto leftSize = lfs.size();
    auto rightSize = rfs.size();
    int32_t size = 0;

    if ( leftSize < rightSize )
    {
        size = rightSize;
    }
    else
    {
        size = leftSize;
    }
    int32_t compCnt = 0;
    while ( compCnt < leftSize * rightSize )
    {
        if ( lfs[ compCnt % leftSize ] > rfs[ compCnt % rightSize ] )
        {
            return true;
        }
        else if ( lfs[ compCnt % leftSize ] < rfs[ compCnt % rightSize ] )
        {
            return false;
        }
        compCnt++;
    }
    return false;
};
}
class PS_16496
{
public:
    PS_16496()
    {
        Init();
    }
    ~PS_16496()
    {
    }
    void Init()
    {
        convDatas.clear();
        isNotZero = false;
    }

    std::string Execute( std::vector<int32_t>& inputDatas )
    {
        std::string ret;
        ret.reserve( 10000 );
        SetDatas( inputDatas );
        std::sort( convDatas.begin(), convDatas.end(), ps16496::Compare );

        if ( isNotZero )
        {
            for ( auto convData : convDatas )
            {
                ret += convData;
            }
        }
        else
        {
            ret += "0";
        }

        return ret;
    }

private:
    std::vector<std::string> convDatas = {};
    bool isNotZero = false;
private:
    void SetDatas( const std::vector<int32_t>& inputDatas )
    {
        for ( auto inputData : inputDatas )
        {
            if ( !isNotZero && inputData != 0 )
            {
                isNotZero = true;
            }
            convDatas.push_back( std::to_string( inputData ) );
        }
    }
};
