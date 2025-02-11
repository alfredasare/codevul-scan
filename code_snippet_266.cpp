Class Layer {
public:
//...
mutable std::mutex mtx_;
//...
};

bool Layer::FilterIsAnimating() const {
std::unique\_lock<std::mutex> lock(mtx_); // Lock the mutex
return layer\_animation\_controller\_->IsAnimatingProperty(Animation::Filter);
}