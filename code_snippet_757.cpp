perf_event_mux_interval_ms_store(struct device *dev,
 struct device_attribute *attr,
 const char __user *buf, size_t count)
{
 struct pmu *pmu = dev_get_drvdata(dev);
 int timer, cpu, ret;
 char tmp[16]; /* adjust buffer size as needed */

 if (count > sizeof(tmp))
 return -ERANGE;

 ret = copy_from_user(tmp, buf, count);
 if (ret)
 return ret;

 ret = kstrtoint(tmp, 0, &timer);
 if (ret)
 return ret;

 // ... rest of the function ...
}