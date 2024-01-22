using System;

namespace DeviceDriver
{
    public class Required : ValidationAttribute
    {
        public override bool isValid(object id)
        {
            return !string.IsNullOrEmpty((string)id);
        }
    }
}