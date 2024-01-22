using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace DeviceDriver
{
    internal class RegexAttribute : ValidationAttribute
    {
        public string Pattern { get; set; }
        RegexAttribute(string pattern)
        {
            Pattern = pattern;
        }
        public override bool isValid(object validationParam)
        {
            string text = (string)validationParam;
            return Regex.IsMatch(text, Pattern);
        }
    }
}
