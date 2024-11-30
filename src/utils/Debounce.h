unsigned long lastDebounceTime = 0;
unsigned long lastISRTime = 0;

void debounce(const unsigned long &timeNow, void fn(), unsigned long delay = 50)
{
    if (timeNow - lastDebounceTime > delay)
    {
        fn();
        lastDebounceTime = timeNow;
    }
}

void isr_debounce(const unsigned long &timeNow, void fn(), unsigned long delay = 50)
{
    if (timeNow - lastISRTime > delay)
    {
        fn();
    }
    lastISRTime = timeNow;
}
