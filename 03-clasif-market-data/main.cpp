
#include "Precio.h"
#include "file_util.h"

int main() {
    using namespace std;
    map<int, Precio> precios{};
    map<string, map<time_t, vector<Precio>>> preciosSeparados{};
    map<string, map<time_t, Precio>> preciosAgrupados{};
    
    fut::read("res/default_data.txt", precios);

    emparejarPrecios(precios, preciosSeparados);

    agruparPrecios(preciosSeparados, preciosAgrupados);

    fut::write("out/", preciosAgrupados);
}