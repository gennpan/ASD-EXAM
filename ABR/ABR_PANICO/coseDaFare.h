#ifndef coseDaFare_h
#define coseDaFare_h


#include <string>


class coseDaFare 
{
    private: 
        int priorita;
        std::string descrizione;

    public:
        coseDaFare(std::string x, int y) {priorita = y; descrizione = x;}
        coseDaFare(const coseDaFare &cdf)
        {
                this->priorita = cdf.priorita; 
                this->descrizione = cdf.descrizione;
        }
        
        void setPriorita(int x) {priorita = x;}
        void setDesc(string x) {descrizione = x;}

        int getPriorita() {return this->priorita;}
        std::string getDesc() {return this->descrizione;}

        friend std::ostream &operator<<(std::ostream &out, const coseDaFare &cdf)
        {
            out << "\"" << cdf.descrizione << "\" (" << cdf.priorita << ")\n";
            return out;
        }        

        bool operator<(const coseDaFare &cdf) {
            return this -> priorita < cdf.priorita; 
        }



};


#endif