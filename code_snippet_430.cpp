#include <mutex>

class LayerTreeHostImpl {
public:
    // ...

private:
    std::mutex scroll_mutex_;

    bool GetScrollOffsetForLayer(int layer_id, gfx::ScrollOffset* offset) {
        std::unique_lock<std::mutex> lock(scroll_mutex_);
        LayerImpl* layer = active_tree()->FindActiveTreeLayerById(layer_id);
        if (!layer)
            return false;

        *offset = layer->CurrentScrollOffset();
        return true;
    }
};