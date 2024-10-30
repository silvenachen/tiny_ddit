#include "kernel.h"
//# include "xcl2.hpp"
# include <fstream>
#include <iostream>
#include <vector>

#define L 64
#define D 32
#define Cond 8
#define H 8

// void load_in_params();
// void load_array_from_file(const std::string &filename, float* array, int size);

// void print_array_values(const std::string &name, const float* array, int size) {
//     std::cout << "values of " << name << ":" << std::endl;
//     for (int i = 0; i < size; i++) {
//         std::cout << array[i] << " ";
//     }
//     std::cout << std::endl;
// }


void load_array_from_file(const std::string &filename, float* array, int size);


int main(void){

    // std::vector<float> input(L * D, 0);
    // std::vector<float> gamma_arr(D, 0);
    // std::vector<float> beta(D, 0);
    // std::vector<float> sin_arr(L * 32, 0);
    // std::vector<float> cos_arr(L * 32, 0);
    // std::vector<float> q_weight(D * D, 0);
    // std::vector<float> k_weight(D * D, 0);
    // std::vector<float> v_weight(D * D, 0);
    // std::vector<float> c(Cond, 0);
    // std::vector<float> adaLN_weight(Cond * 6 * D, 0);
    // std::vector<float> adaLN_bias(6 * D, 0);
    // std::vector<float> shift_msa(D, 0);
    // std::vector<float> scale_msa(D, 0);
    // std::vector<float> gate_msa(D, 0);
    // std::vector<float> shift_mlp(D, 0);
    // std::vector<float> scale_mlp(D, 0);
    // std::vector<float> gate_mlp(D, 0);
    // std::vector<float> attn_out_weight(D * D, 0);
    // std::vector<float> x_skip(L * D, 0);
    // std::vector<float> mlp1_weight(D * D, 0);
    // std::vector<float> mlp1_bias(D, 0);
    // std::vector<float> mlp2_weight(D * D, 0);
    // std::vector<float> mlp2_bias(D, 0);
    // std::vector<float> output(L * D, 0);


    std::string path = "/home/silvenchen/Desktop/mdlm/FPGA-based-Accelerator-for-Diffusion-Language-Models/DDit_Tiny_WorkDict/data_file/";
    std::cout << "start loading files" << std::endl;
    // load_array_from_file(path + "x.txt", input.data(), L*D);
    // load_array_from_file(path + "gamma.txt", gamma_arr.data(), D);
    // load_array_from_file(path + "beta.txt", beta.data(), D);
    // load_array_from_file(path + "sin.txt", sin_arr.data(), L*32);
    // load_array_from_file(path + "cos.txt", cos_arr.data(), L*32);
    // load_array_from_file(path + "q_weight.txt", q_weight.data(), D*D);
    // load_array_from_file(path + "k_weight.txt", k_weight.data(), D*D);
    // load_array_from_file(path + "v_weight.txt", v_weight.data(), D*D);
    // load_array_from_file(path + "c.txt", c.data(), Cond);
    // load_array_from_file(path + "adaLN_weight.txt", adaLN_weight.data(), Cond*6*D);
    // load_array_from_file(path + "adaLN_bias.txt", adaLN_bias.data(), 6*D);
    // load_array_from_file(path + "shift_msa.txt", shift_msa.data(), D);
    // load_array_from_file(path + "scale_msa.txt", scale_msa.data(), D);
    // load_array_from_file(path + "gate_msa.txt", gate_msa.data(), D);
    // load_array_from_file(path + "shift_mlp.txt", shift_mlp.data(), D);
    // load_array_from_file(path + "scale_mlp.txt", scale_mlp.data(), D);
    // load_array_from_file(path + "gate_mlp.txt", gate_mlp.data(), D);
    // load_array_from_file(path + "attn_out_weight.txt", attn_out_weight.data(), D*D);
    // load_array_from_file(path + "x.txt", x_skip.data(), L*D);
    // load_array_from_file(path + "mlp1_weight.txt", mlp1_weight.data(), D*D);
    // load_array_from_file(path + "mlp1_bias.txt", mlp1_bias.data(), D);
    // load_array_from_file(path + "mlp2_weight.txt", mlp2_weight.data(), D*D);
    // load_array_from_file(path + "mlp2_bias.txt", mlp2_bias.data(), D);
    float c[1][8] = {0};  // Adapting `c` to a 2D array for systolic_modulate
    float adaLN_weight[8][192] = {0}; // Reshape `adaLN_weight` as needed

    // Output array for results
    float output[1][192] = {0};

    load_array_from_file("/home/silvenchen/Desktop/mdlm/FPGA-based-Accelerator-for-Diffusion-Language-Models/DDit_Tiny_WorkDict/data_file/c.txt", &c[0][0], Cond);
    load_array_from_file("/home/silvenchen/Desktop/mdlm/FPGA-based-Accelerator-for-Diffusion-Language-Models/DDit_Tiny_WorkDict/data_file/adaLN_weight.txt", &adaLN_weight[0][0], Cond * 6 * D);
    
    std::cout << "finish loading files" << std::endl;

    //load input and parameters from files
    // load_in_params();
    // print_array_values("mlp2_bias", input, L*D);
    // std::cout << "Input Address: " << input.data() << std::endl;
    // std::cout << "Gamma_arr Address: " << gamma_arr.data() << std::endl;
    // std::cout << "Beta Address: " << beta.data() << std::endl;
    //compute
    std::cout << "start computing" << std::endl;
    systolic_modulate(c, adaLN_weight, output);

    // allo_DDitBlock(
    //     input.data(),
    //     gamma_arr.data(),
    //     beta.data(),
    //     sin_arr.data(),
    //     cos_arr.data(),
    //     q_weight.data(),
    //     k_weight.data(),
    //     v_weight.data(),
    //     c.data(),
    //     adaLN_weight.data(),
    //     adaLN_bias.data(),
    //     shift_msa.data(),
    //     scale_msa.data(),
    //     gate_msa.data(),
    //     shift_mlp.data(),
    //     scale_mlp.data(),
    //     gate_mlp.data(),
    //     attn_out_weight.data(),
    //     x_skip.data(),
    //     mlp1_weight.data(),
    //     mlp1_bias.data(),
    //     mlp2_weight.data(),
    //     mlp2_bias.data(),
    //     output.data()
    // );
    // systolic_modulate(
    // float v67[1][8],
    // float v68[8][192],
    // float v69[1][192]
    // )
    // std::cout << "finishing computing, saving output" << std::endl;

    std::ofstream out_file("/home/silvenchen/output.txt");
    if (out_file.is_open()) {
        // for (int i = 0; i < L; i++) {
        //     for (int j = 0; j < D; j++) {
        //         out_file << output[i * D + j] << (j < D - 1 ? " " : "\n");
        //     }
        // }
        for(int i = 0; i < 1; i++){
            for (int j = 0; j < 192; j++){
                out_file << output[0][j] << (" ");
            }
        }
        out_file.close();
    } else {
        std::cout << "Failed to open output.txt for writing." << std::endl;
    }

    // Finish processing.
    return 0;
}

// void load_array_from_file(const std::string &filename, float* array, int size){
//     std::ifstream infile(filename);
//     if(!infile.is_open()){
//         std::cout << "Error opening file " << filename << std::endl;
//         return;
//     }

//     for (int i = 0; i < size; i++){
//         infile >> array[i];
//     }
//     infile.close();
// }
void load_array_from_file(const std::string &filename, float* array, int size) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        infile >> array[i];
    }
    infile.close();
}