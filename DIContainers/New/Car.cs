public class Car
{
    private readonly IEngine engine;
    private readonly ITransmission transmission;

    public Car(IEngine engine, ITransmission transmission)
    {
        this.engine = engine;
        this.transmission = transmission;
    }
}
