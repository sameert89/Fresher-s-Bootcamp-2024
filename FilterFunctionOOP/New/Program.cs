using System;
using FilterFunction.SearchStrategies;
namespace FilterFunction 
{
    class Program
    {
        static void Main()
        {
            var startsWithStrategy = new StartsWithStrategy();
            startsWithStrategy.SetStartsWith("R");
            var stringListFilterController = new StringListFilterController();
            stringListFilterController.SetSearchStrategy(startsWithStrategy);
        }
    } 
}
