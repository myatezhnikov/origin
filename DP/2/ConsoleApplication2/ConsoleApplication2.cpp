#include <map>
#include <string>
#include <iostream>
using namespace std;

class VeryHeavyDatabase {
public:
   virtual string GetData(const string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class OneShotDB : public VeryHeavyDatabase          //дополнительный класс с лимитом получения данных
{
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots = 1)
        : real_object_(real_object), remaining_shots_(shots) { }

    string GetData(const string& key) const noexcept override 
    {
        if (remaining_shots_ == 0) 
        {
            return "error";
        }
        --remaining_shots_;
        return real_object_->GetData(key);
    }

private:
    VeryHeavyDatabase* real_object_;
    mutable size_t remaining_shots_; // mutable, чтобы можно было изменять в const методе
};

class CacheProxyDB : public VeryHeavyDatabase 
{
public:
    explicit CacheProxyDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    string GetData(const string& key) noexcept 
    {
        if (cache_.find(key) == cache_.end()) 
        {
            cout << "Get from real object\n";
            cache_[key] = real_db_->GetData(key);
        }
        else 
        {
            cout << "Get from cache\n";
        }
        return cache_.at(key);
    }

private:
    map<string, string> cache_;
    VeryHeavyDatabase* real_db_;
};

class TestDB : VeryHeavyDatabase 
{
public:
    explicit TestDB(VeryHeavyDatabase* real_object) : real_db_(real_object) {}
    string GetData(const string& key) noexcept 
    {
        return "test_data\n";
    }
private:
    VeryHeavyDatabase* real_db_;
};

int main() {
  /*  auto real_db = VeryHeavyDatabase();
    auto cached_db = CacheProxyDB(std::addressof(real_db));
    auto test_db = TestDB(std::addressof(real_db));
    cout << cached_db.GetData("key") << endl;
    cout << cached_db.GetData("key") << endl;
    cout << test_db.GetData("key") << endl;
   */
    auto real_db = VeryHeavyDatabase();
    auto limit_db = OneShotDB(addressof(real_db), 2);

    cout << limit_db.GetData("key") << endl; 
    cout << limit_db.GetData("key") << endl; 
    cout << limit_db.GetData("key") << endl; 
}