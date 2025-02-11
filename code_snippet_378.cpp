BlockEntry::Kind SimpleBlock::GetKind() const
{
    BlockEntry::Kind kind = kBlockSimple;
    if (kind != BlockEntry::Kind::kBlockSimple)
    {
        std::cerr << "Unexpected BlockEntry::Kind value: " << static_cast<int>(kind) << std::endl;
        kind = BlockEntry::Kind::kBlockInvalid;
    }
    return kind;
}