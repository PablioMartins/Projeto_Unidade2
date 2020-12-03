#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief A struct Voxel corresponde ao "pixel 3d" carregando as caracteristica de um
 * ponto no espaço, como: cor, transparêcia e se ele esta visível ou não.
 */
struct Voxel{
    /**
     * @brief r é uma variável para atribução de cor, "r" ou "red" do inglês corresponde ao
     * filtro vermelho, valores que a variável deve assumir "0" á "1".
     */
    float r;

    /**
     * @brief g é uma variável para atribução de cor, "g" ou "green" do inglês corresponde ao
     * filtro verde, valores que a variável deve assumir "0" á "1".
    */
    float g;

    /**
     * @brief b é uma variável para atribução de cor, "b" ou "blue" do inglês corresponde ao
     * filtro azul, valores que a variável deve assumir "0" á "1".
    */
    float b;//Cores

    /**
     * @brief a é uma variável que traz caracteristicas de transparência valores que devem ser
     * atribuidos estão na faixa de "0" á "1".
     */
    float a;//tranparencia

    /**
     * @brief isOn é uma variável de estado que pode assumir valores lógicos "true" ou "false",
     * corresponde ao voxel de uma determinada posição do espaço está visível (ativo) ou não (inativo).
     */
    bool isOn;//esta ativo ou nao
};

/**
 * @brief A classe sculptor é a classe responssavel por "desenhar" voxels ou formas no espaço assim como
 * gerar o arquivo ".OFF" para visualização em outros softwares.
 */
class sculptor {
protected:
    /**
    * @brief v é um array (vetor) protegida da classe sculptor responsável pelo endereço das posições
    * da matriz tridimensional de voxels
    */
    Voxel ***v;
    // 3D matrix

    /**
     * @brief nx é o comprimento na direção "x" da matriz de voxels.
     */
    int nx;

    /**
     * @brief ny é o comprimento na direção "y" da matriz de voxels.
     */
    int ny;

    /**
     * @brief nz é o comprimento na direção "z" da matriz de voxels.
     */
    int nz; // Dimensions

    /**
     * @brief r é uma variável para atribução de cor, "r" ou "red" do inglês corresponde ao
     * filtro vermelho, valores que a variável deve assumir "0" á "1".
     */
    float r;

    /**
     * @brief g é uma variável para atribução de cor, "g" ou "green" do inglês corresponde ao
     * filtro verde, valores que a variável deve assumir "0" á "1".
    */
    float g;

    /**
     * @brief b é uma variável para atribução de cor, "b" ou "blue" do inglês corresponde ao
     * filtro azul, valores que a variável deve assumir "0" á "1".
    */
    float b;

    /**
     * @brief a é uma variável que traz caracteristicas de transparência valores que devem ser
     * atribuidos estão na faixa de "0" á "1".
     */
    float a; // Current drawing color
public:

   /**
   * @brief O sculptor é o construtor da classe, responsável pela criação e alocação dinâmica da memória,
   * para a matriz tridimencional que será utilizada para criação de esculturas tridimencionais.
   * Está e a primeira função a ser chamada no código.
   * @param _nx é o tamanho em "x" da matriz que será alocada.
   * @param _ny é o tamanho em "y" da matriz que será alocada.
   * @param _nz é o tamanho em "z" da matriz que será alocada.
   */
  sculptor(int _nx, int _ny, int _nz);

  /**
  * @brief Destrutor da classe sculptor
  */
  ~sculptor();

  /**
   * @brief setColor seleciona a cor do objeto a ser desenhado, quando chamada no código todos os objetos desenhados
   * após a função serão da cor atribuida a mesma.
   * @param r é o filtro vermelho, valores que devem ser atribuidos na faixa "0" á "1".
   * @param g é o filtro verde, valores que devem ser atribuidos na faixa "0" á "1".
   * @param b é o filtro azul, valores que devem ser atribuidos na faixa "0" á "1".
   * @param alpha é a transparência, valores que devem ser atribuidos na faixa "0" á "1".
   */
  void setColor(float r, float g, float b, float alpha);

  /**
   * @brief putVoxel habilita a visualização de um "pixel" em uma dada posição no espaço, dentro da faixa predefinida
   * na criação do "sculptor".
   * @param x é uma coordenada na direção "x" do espaço.
   * @param y é uma coordenada na direção "y" do espaço.
   * @param z é uma coordenada na direção "z" do espaço.
   */
  void putVoxel(int x, int y, int z);

  /**
   * @brief cutVoxel desabilita a visualização de um "pixel" em uma dada posição no espaço.
   * @param x é uma coordenada na direção "x" do espaço.
   * @param y é uma coordenada na direção "y" do espaço.
   * @param z é uma coordenada na direção "z" do espaço.
   */
  void cutVoxel(int x, int y, int z);

  /**
   * @brief putBox habilita uma "caixa" em uma dada região do espaço, dentro da faixa predefinida na criação do "sculptor".
   * @param x0 é a posição inicial da orientação "x" no espaço.
   * @param x1 é a posição final da orientação "x" no espaço.
   * @param y0 é a posição inicial da orientação "y" no espaço.
   * @param y1 é a posição final da orientação "y" no espaço.
   * @param z0 é a posição inicial da orientação "z" no espaço.
   * @param z1 é a posição final da orientação "z" no espaço.
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
   * @brief cutBox desabilita uma "caixa" em uma dada região do espaço, dentro da faixa predefinida na criação do "sculptor".
   * @param x0 é a posição inicial da orientação "x" no espaço.
   * @param x1 é a posição final da orientação "x" no espaço.
   * @param y0 é a posição inicial da orientação "y" no espaço.
   * @param y1 é a posição final da orientação "y" no espaço.
   * @param z0 é a posição inicial da orientação "z" no espaço.
   * @param z1 é a posição final da orientação "z" no espaço.
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
   * @brief putSphere habilita uma "esfera" em uma dada região do espaço, dentro da faixa predefinida na criação do "sculptor".
   * @param xcenter é a posição do centro da "esfera" na coordenada "x" no espaço.
   * @param ycenter é a posição do centro da "esfera" na coordenada "y" no espaço.
   * @param zcenter é a posição do centro da "esfera" na coordenada "z" no espaço.
   * @param radius é o raio da esfera.
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
   * @brief cutSphere desabilita uma "esfera" em uma dada região do espaço, dentro da faixa predefinida na criação do "sculptor".
   * @param xcenter é a posição do centro da "esfera" na coordenada "x" no espaço.
   * @param ycenter é a posição do centro da "esfera" na coordenada "y" no espaço.
   * @param zcenter é a posição do centro da "esfera" na coordenada "z" no espaço.
   * @param radius é o raio da esfera.
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
   * @brief putEllipsoid habilita uma "elipsóide" em uma dada região do espaço,
   * dentro da faixa predefinida na criação do "sculptor".
   * @param xcenter é a posição do centro da "elipsóide" na coordenada "x" no espaço.
   * @param ycenter é a posição do centro da "elipsóide" na coordenada "y" no espaço.
   * @param zcenter é a posição do centro da "elipsóide" na coordenada "z" no espaço.
   * @param rx é o raio da "elipsóide" na direção "x".
   * @param ry é o raio da "elipsóide" na direção "y".
   * @param rz é o raio da "elipsóide" na direção "z".
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
   * @brief cutEllipsoid desabilita uma "elipsóide" em uma dada região do espaço,
   * dentro da faixa predefinida na criação do "sculptor".
   * @param xcenter é a posição do centro da "elipsóide" na coordenada "x" no espaço.
   * @param ycenter é a posição do centro da "elipsóide" na coordenada "y" no espaço.
   * @param zcenter é a posição do centro da "elipsóide" na coordenada "z" no espaço.
   * @param rx é o raio da "elipsóide" na direção "x".
   * @param ry é o raio da "elipsóide" na direção "y".
   * @param rz é o raio da "elipsóide" na direção "z".
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
   * @brief writeOFF responsável pela criação do arquivo ".OFF" a ser lido por softwares de renderização 3d.
   * @param filename e o nome do arquivo que será salvo.
   */
  void writeOFF(char* filename);
};

#endif // SCULPTOR_H
