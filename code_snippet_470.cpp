static void Ins_ROUND(INS_ARG) {
    if (!isValidInputFormat(args[0])) {
        throw new InvalidInputException("Invalid input format");
    }
    args[0] = deserializeInput(args[0], CUR.metrics.compensations[CUR.opcode - 0x68]);
}

private boolean isValidInputFormat(String input) {
    String[] allowedFormats = {"format1", "format2", "format3"};
    for (String format : allowedFormats) {
        if (input.matches(format)) {
            return true;
        }
    }
    return false;
}

private String deserializeInput(String input, Object obj) {
    JsonNode jsonNode = Json.parse(input);
    ObjectMapper mapper = new ObjectMapper();
    return mapper.treeToValue(jsonNode, obj.getClass());
}