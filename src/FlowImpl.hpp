/**
 * @file FlowImpl.hpp
 * @brief Implementação concreta da interface Flow.
 */
#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

#include "Flow.hpp"
#include "System.hpp"
/**
 * @class FlowImpl
 * @brief Implementação base de um fluxo da simulação.
 *
 * Armazena as informações comuns a todos os fluxos:
 * nome, sistema de origem e sistema de destino.
 *
 * As classes derivadas são responsáveis por implementar
 * a equação específica do fluxo.
 */
class FlowImpl : public Flow
{
protected:
    /**
     * @brief Nome identificador do fluxo.
     */
    std::string name;
    /**
     * @brief Sistema de origem do fluxo.
     */
    System *source;
    /**
     * @brief Sistema de destino do fluxo.
     */
    System *target;

public:
    /**
     * @brief Construtor padrão.
     */
    FlowImpl();
    /**
     * @brief Construtor parametrizado.
     *
     * @param name Nome do fluxo.
     * @param source Sistema de origem.
     * @param target Sistema de destino.
     */
    FlowImpl(std::string, System *, System *);
    /**
     * @brief Construtor de cópia.
     *
     * @param copy Fluxo que será copiado.
     */
    FlowImpl(const FlowImpl &copy);
    /**
     * @brief Operador de atribuição.
     *
     * @param copy Fluxo que será atribuído.
     *
     * @return Referência para o próprio objeto.
     */
    FlowImpl &operator=(const FlowImpl &);
    /**
     * @brief Destrutor.
     */

    virtual ~FlowImpl();
    /**
     * @brief Define o sistema de origem.
     *
     * @param source Novo sistema de origem.
     */
    void setSource(System *);
    /**
     * @brief Retorna o sistema de origem.
     *
     * @return Sistema de origem.
     */
    System *getSource() const;
    /**
     * @brief Define o sistema de destino.
     *
     * @param target Novo sistema de destino.
     */
    void setTarget(System *);
    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Sistema de destino.
     */
    System *getTarget() const;
    /**
     * @brief Retorna o nome do fluxo.
     *
     * @return Nome identificador.
     */
    std::string getName() const;
    /**
     * @brief Define o nome do fluxo.
     *
     * @param name Novo nome.
     */
    void setName(const std::string &);
    /**
     * @brief Remove o sistema de origem.
     *
     * Define o ponteiro de origem como nulo.
     */
    void removeSource();
    /**
     * @brief Remove o sistema de destino.
     *
     * Define o ponteiro de destino como nulo.
     */
    void removeTarget();
    /**
     * @brief Executa o fluxo.
     *
     * @return Valor resultante da execução.
     */
    virtual double equation() = 0;
};

#endif