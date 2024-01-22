using System;

namespace DeviceDriver
{
    public class Range : ValidationAttribute
    {
        private int Min { get; set; }
        private int Max { get; set; }

        public Range(int min, int max, string message)
        {
            Min = min;
            Max = max;
            ErrorMessage = message;
        }

        public override bool isValid(object code)
        {
            return (int)code >= Min && (int)code <= Max;
        }
    }
}