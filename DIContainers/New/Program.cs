using System;
using Microsoft.Extensions.DependencyInjection;

class Program
{
    static void Main()
    {
        var serviceProvider = new ServiceCollection()
            .AddTransient<IEngine, Engine>()
            .AddTransient<ITransmission, Transmission>()
            .AddTransient<IStartupMotor, StartupMotor>()
            .AddTransient<IFuelPump, FuelPump>()
            .AddTransient<Car>()
            .BuildServiceProvider();

        var car = serviceProvider.GetService<Car>();
    }
}
