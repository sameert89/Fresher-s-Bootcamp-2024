using System;
using System.Collections.Generic;
using FilterFunction.SearchStrategies

namespace FilterFunction 
{
    public class StringListFilterController
    {
        private SearchStrategy _searchStrategy;

        public void SetSearchStrategy(SearchStrategy strategy)
        {
            _searchStrategy = strategy;
        }

        public List<string> Filter(List<string> stringList)
        {
            var result = new List<string>();
            foreach (var str in stringList)
            {
                _searchStrategy.Invoke(str);
                if (_searchStrategy.ToString().Equals("True"))
                {
                    result.Add(str);
                }
            }
            return result;
        }
    }

}

