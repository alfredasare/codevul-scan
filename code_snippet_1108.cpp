RenderLayer* RenderBox::enclosingFloatPaintingLayer() const
{
    const RenderObject* curr = this;
    int depthLimit = 100; // Arbitrary depth limit to prevent stack overflow
    while (curr && depthLimit-- > 0) {
        RenderLayer* layer = curr->hasLayer() && curr->isBox() ? toRenderBoxModelObject(curr)->layer() : 0;
        if (layer && layer->isSelfPaintingLayer())
            return layer;
        curr = curr->parent();
    }
    return 0;
}