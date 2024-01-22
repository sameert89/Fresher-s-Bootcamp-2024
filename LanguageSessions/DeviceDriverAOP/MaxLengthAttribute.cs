using System;

namespace DeviceDriver
{
    public class MaxLength : ValidationAttribute
    {
        public int maxLength;

        public MaxLength(int maxLength, string errorMessage)
        {
            this.maxLength = maxLength;
            ErrorMessage = errorMessage;
        }

        public override bool isValid(object description)
        {
            return ((string)description).Length <= maxLength;
        }
    }
}