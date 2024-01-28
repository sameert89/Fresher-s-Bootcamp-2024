namespace FilterFunction
{
    public class StartsWithStrategy : SearchStrategy
    {
        private string _startsWith;

        public void SetStartsWith(string key)
        {
            _startsWith = key;
        }

        public override bool Invoke(string item)
        {
            return item.StartsWith(_startsWith);
        }
    }


}
