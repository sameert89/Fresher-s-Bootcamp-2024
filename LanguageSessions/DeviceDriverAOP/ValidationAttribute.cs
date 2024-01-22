using System;

namespace DeviceDriver
{
    public abstract class ValidationAttribute : Attribute
    {
        public string ErrorMessage;
        public abstract bool isValid(object validationParam);
    }
}