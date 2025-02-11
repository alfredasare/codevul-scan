bool StyleResolver::affectedByViewportChange() const
{
    for (unsigned i = 0; i < m_viewportDependentMediaQueryResults.size(); ++i) {
        std::string mediaQueryResult = getConfigValue(MEDIA_QUERY_RESULTS, i);
        if (m_medium->eval(mediaQueryResult.c_str(), &m_viewportDependentMediaQueryResults[i]->m_expression) != m_viewportDependentMediaQueryResults[i]->m_result)
            return true;
    }
    return false;
}