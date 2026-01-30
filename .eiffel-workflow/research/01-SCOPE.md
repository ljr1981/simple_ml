# SCOPE: simple_ml

## Problem Statement

**In one sentence:** Enterprise and educational applications need contract-verified machine learning algorithms integrated with Eiffel's Design by Contract and the simple_* ecosystem.

**What's wrong today:**
- Machine learning libraries in other languages lack formal verification
- No production-ready ML library in Eiffel with contract-based correctness
- Existing Python/R ML libraries (scikit-learn, TensorFlow) are difficult to integrate with formal verification systems
- Companies need certified ML models for regulated domains (healthcare, finance, autonomous systems)

**Who experiences this:**
- Enterprise developers building safety-critical AI systems
- Academic researchers using Eiffel for verification work
- Fintech and healthtech companies needing formal guarantees on ML predictions
- Autonomous vehicle developers requiring provably correct decision logic

**Impact of not solving:**
- ML adoption in regulated industries remains limited without formal verification
- Eiffel ecosystem lacks a key computational domain
- Missed opportunity to position Eiffel as the formal-methods leader in ML

## Target Users

| User Type | Needs | Pain Level |
|-----------|-------|------------|
| Enterprise Data Scientists | Provably correct models, auditability, formal contracts | HIGH |
| Research Institutions | Verification capabilities, educational tool | HIGH |
| FinTech/HealthTech Developers | Regulatory compliance, certification trails | HIGH |
| Autonomous Systems Engineers | Safety guarantees on decision functions | HIGH |
| Academic Researchers | Teaching formal methods + ML combined | MEDIUM |

## Success Criteria

| Level | Criterion | Measure |
|-------|-----------|---------|
| MVP | Core supervised learning algorithms with contracts | 5 algorithms: Linear/Logistic Regression, Decision Tree, Random Forest, SVM, Neural Network (basic) |
| MVP | Model evaluation framework with contracts | Accuracy, Precision, Recall, F1, ROC-AUC metrics with preconditions |
| MVP | Data preprocessing pipeline | Normalization, standardization, feature scaling with DBC contracts |
| MVP | Integration with simple_* ecosystem | Builds on simple_optimization, simple_linalg, simple_statistics, simple_montecarlo |
| MVP | 100% Design by Contract | Every algorithm has require/ensure/invariant clauses |
| Full | Advanced algorithms | Gradient boosting, ensemble methods, kernel methods |
| Full | Time series support | ARIMA, Prophet, LSTM basics |
| Full | Clustering algorithms | K-means, hierarchical clustering, DBSCAN |
| Full | Dimensionality reduction | PCA, t-SNE, UMAP |

## Scope Boundaries

### In Scope (MUST)

- **Supervised Learning:** Linear regression, logistic regression, decision trees, random forests, support vector machines (SVM), basic neural networks
- **Evaluation Metrics:** Accuracy, precision, recall, F1-score, ROC-AUC, confusion matrices
- **Data Preprocessing:** Feature scaling, normalization, standardization, train-test splits
- **Model Training:** Gradient descent variants, tree-based methods, ensemble averaging
- **Contracts on Everything:** Every class, every feature has complete require/ensure/invariant clauses
- **Integration:** Leverage simple_optimization for gradient descent, simple_linalg for matrix operations, simple_statistics for distributions
- **Eiffel Idioms:** SCOOP-compatible, void-safe, command-query separation, reusable generics

### In Scope (SHOULD)

- Hyperparameter tuning with grid search
- Cross-validation frameworks
- Feature importance analysis
- Model serialization (save/load trained models)
- Basic visualization hooks (for external GUI tools)

### Out of Scope

- **GPU acceleration (MVP CPU-only, GPU Phase 1.5+):** See GPU Strategy section below. MVP targets verification correctness. Phase 1.5 adds GPU support via C/C++ CUDA/cuBLAS bindings (separate from Eiffel contracts) after MVP foundation is verified.
- **Distributed training:** Too complex for MVP; consider Phase 2. See Distributed Training Definition below.
- **Deep learning frameworks:** TensorFlow-scale complexity; keep neural networks basic in MVP
- **Graph neural networks:** Specialized domain; Phase 2+. Requires graph data structures and specialized backpropagation algorithms.
- **Reinforcement learning:** Different paradigm; separate library (future simple_rl). RL requires exploration/exploitation trade-offs, state/action spaces, reward signals - orthogonal to supervised learning.
- **AutoML/NAS:** Automated machine learning beyond scope; Phase 2. See AutoML/NAS Definition below.
- **Causal inference:** Statistical specialty beyond MVP scope. See Causal Inference Justification below.
- **Natural language processing:** NLP-specific domain; future simple_nlp library. NLP requires tokenization, embeddings, language-specific preprocessing.

### Deferred to Future (with Justifications)

#### GPU/CUDA Support (Phase 1.5+, not Phase 2)
**UPDATED: GPU support moved to Phase 1.5 (between MVP verification and Phase 2 scaling)**
- MVP Phase 1-3: CPU-only verification (Design by Contract foundation)
- **Phase 1.5 (new):** CUDA/cuBLAS integration via C/C++ bindings for matrix operations
- Phase 2: Distributed GPU training (multi-GPU, multi-node)
- Rationale: Users with NVIDIA GPUs (like 5070 Ti 16GB) need acceleration NOW, not in Phase 2. Strategy: Eiffel contracts stay CPU-focused (simple_linalg matrices). Accelerated kernels (matrix multiply, gradient computation) delegate to C/C++ CUDA libraries with Eiffel bindings. Verification contracts on Eiffel layer; CUDA code is trusted external library.
- Implementation: `simple_linalg` matrix ops could use cuBLAS as optional backend; simple_optimization gradient descent could use cuDNN for tensor operations.

#### Distributed Training (Phase 2+)
**Definition:** Training a single model across multiple computers/GPUs, each processing different data batches and sharing gradients via network communication (AllReduce, parameter servers).

**Why Phase 2+, not MVP:**
- MVP target: single machine (CPU or single GPU)
- Distributed requires: MPI/NCCL communication libraries, data partitioning strategy, fault tolerance, synchronization primitives
- Complexity: 3-4x harder than single-machine training (handles stragglers, network failures, gradient synchronization)
- Eiffel ecosystem gap: No simple_mpi or simple_distributed library exists yet
- Research needed first: How to distribute while maintaining Design by Contract guarantees across network boundaries
- Phase 2: After MVP is production-proven, consider Phase 2 for multi-GPU/multi-node with new simple_distributed library

#### Large-scale Dataset Support (Phase 2+)
- MVP: Datasets fit in RAM (~100MB typical)
- Phase 2: Streaming/mini-batch from disk, out-of-core algorithms
- Rationale: Adds complexity (I/O management, shuffling, caching). MVP doesn't need this; enterprise use cases are typically <100MB.

#### Advanced Ensemble Methods (Phase 2+)
- MVP: Random Forest (bagging), basic averaging
- Phase 2: Stacking, blending, boosting variants
- Rationale: MVP covers 80% of ensemble use cases. Advanced methods (stacking = training meta-models) are specialized.

#### Neural Network Architectures Beyond Basics (Phase 2+)
- MVP: Simple MLP (fully connected, 1-2 hidden layers)
- Phase 2: Convolutional (image), Recurrent (sequences), Attention, Transformers
- Rationale: MLP covers basic NN use cases. Conv/RNN require specialized operations (convolution, LSTM gates) and are domain-specific.

#### AutoML/NAS (Phase 2+)
**Definition (Automated Machine Learning):** Systems that automatically choose algorithm types, hyperparameters, and architectures without human input.
**Definition (Neural Architecture Search):** Algorithms that automatically design optimal neural network topologies.

**Why Phase 2+:**
- MVP: Manual model selection, grid search for hyperparameters
- Phase 2: AutoML would need: hyperparameter tuning (Bayesian optimization, evolutionary algorithms), algorithm selection (TPOT-style), and architecture search (NAS)
- Complexity: Requires meta-learning, search algorithms, ensemble selection
- Eiffel gap: No simple_optimization supports Bayesian optimization or evolutionary algorithms yet
- Phase 2: Build after MVP foundation is solid

#### Causal Inference (Phase 3+, rationale below)
**Definition:** Statistical and algorithmic methods to infer cause-and-effect relationships from observational data (not just correlation). Examples: instrumental variables, propensity score matching, causal forests.

**Why Out of MVP Scope:**
1. **Orthogonal to supervised learning:** Supervised ML predicts Y given X. Causal inference asks "does X cause Y?" - different goal.
2. **Requires domain expertise:** Causal assumptions (unconfoundedness, no hidden variables) need domain knowledge about the problem.
3. **Not needed by MVP users:** Enterprise/healthcare want predictions, not causal explanations (yet). Causal inference is a Phase 3 specialty.
4. **Eiffel library gap:** No simple_causal exists. Would require foundational research.
5. **Contract complexity:** Causal contracts are harder to specify (requires assumptions about causal DAGs, unobserved confounders).
6. **Market mismatch:** Most ML practitioners don't use causal methods. Focus on core supervised learning first.

**Future simple_causal library** (Phase 4+) could provide: causal forests, propensity score weighting, instrumental variables, but not part of simple_ml MVP.

## Constraints

| Type | Constraint | Notes |
|------|------------|-------|
| Technical | Must be SCOOP-compatible and void-safe (Eiffel standards) | Applies to Eiffel code; CUDA code optional |
| Technical | All algorithms must use simple_* libraries where available; no ISE/Gobo linear algebra | Exception: GPU acceleration via C/C++ (cuBLAS, cuDNN) is allowed if wrapped with Eiffel contracts |
| Technical | Numerical stability requirements (IEEE 754 compliance for accuracy) | Both CPU and GPU code must maintain precision |
| Technical | Memory efficiency for datasets up to ~100MB (typical enterprise datasets) | MVP target; Phase 2 can exceed |
| Ecosystem | Must build on simple_optimization, simple_linalg, simple_statistics, simple_montecarlo, simple_random | CPU implementations use simple_* |
| Ecosystem | simple_* first policy: no external ML libraries (scikit-learn, etc.) in implementation | EXCEPTION: C/C++ GPU libraries (NVIDIA CUDA, cuBLAS, cuDNN) allowed for Phase 1.5+ acceleration as external trusted libraries with Eiffel binding layer |
| Ecosystem | GPU support (Phase 1.5+): If used, CUDA/cuBLAS must be optional and Eiffel contracts remain on CPU path | Users with NVIDIA GPUs can accelerate; CPU-only still works. Contracts verify Eiffel layer; CUDA code is trusted external. |
| Legal | MIT License like all simple_* libraries | GPU bindings must respect NVIDIA EULA |
| Educational | Must be comprehensible to graduate students; algorithms not hidden in black boxes | Eiffel code transparent; CUDA kernels are optimization layer (expected to be opaque) |

## Assumptions to Validate

| ID | Assumption | Risk if False |
|----|------------|---------------|
| A-1 | simple_linalg matrix operations sufficient for ML | High - may need to build custom linear algebra optimizations |
| A-2 | simple_optimization gradient descent can scale to 1000s of features | Medium - may need algorithm tuning or Phase 2 redesign |
| A-3 | Eiffel/EiffelStudio performance acceptable for datasets ~100MB | Medium-High - may reveal need for compiled performance optimizations |
| A-4 | Users will adopt contract-verified ML despite performance trade-offs | Medium - market validation needed |
| A-5 | simple_* ecosystem is sufficient; no ISE/Gobo dependencies needed | Low - library stack is comprehensive |
| A-6 | Algorithms maintainability trumps micro-optimizations in Eiffel | High - architectural decision that affects all implementations |

## GPU Strategy (Phase 1.5+)

### Rationale: NVIDIA 5070 Ti Hardware Acceleration

Users with NVIDIA GPUs (like 5070 Ti 16GB VRAM) need ML acceleration. CPU-only training is insufficient for production performance.

### Phase Breakdown

**Phase 1-3 (MVP - CPU):**
- All algorithms implemented in Eiffel
- Use simple_linalg for CPU matrix operations
- Design by Contract on all CPU code
- Baseline performance target: <5 seconds for typical datasets
- If baseline meets production needs, GPU optional

**Phase 1.5 (GPU Integration - NEW):**
- **Timing:** After Phase 3 (MVP verification complete), before Phase 2 (scaling)
- **Scope:** Optional GPU acceleration for matrix operations
- **Implementation:** C/C++ bindings to NVIDIA libraries
  - **cuBLAS**: GPU matrix operations (multiply, transpose, solve)
  - **cuDNN**: GPU neural network operations (convolution, activation, backprop)
  - **CUDA Runtime**: Memory management, kernel dispatch
- **Eiffel Layer:** Contracts stay on CPU side; CUDA code is trusted external library
- **Architecture:**
  ```
  Eiffel Code (with contracts)
       ↓ (calls through wrapper)
  Eiffel-CUDA Binding Layer
       ↓ (uses)
  C/C++ CUDA/cuBLAS/cuDNN Library
       ↓ (executes on)
  NVIDIA 5070 Ti GPU
  ```
- **Key Principle:** Verification contracts are on Eiffel layer. CUDA is trusted external code (like ISE base library).

**Phase 1.5 Implementation Details:**
- Create `gpu_backends/` directory with C/C++ CUDA code
- Create Eiffel wrapper classes: `GPU_MATRIX_OPERATIONS`, `GPU_NEURAL_NETWORK_KERNELS`
- Wrappers have Eiffel contracts (preconditions, postconditions)
- CUDA kernel implementation is optional backend
- Users choose at runtime: CPU (simple_linalg) vs GPU (CUDA)
- Backward compatibility: CPU path (without CUDA) must work identically

**Phase 2+ (Distributed GPU):**
- Multi-GPU training on single machine (NCCL)
- Multi-node training (NCCL + Ethernet)
- Requires Phase 1.5 GPU foundation

### GPU Performance Expectations

**5070 Ti Specifications:**
- VRAM: 16GB (sufficient for large ML datasets)
- Compute: ~1,300+ TFLOPS FP32 (vs CPU ~100 GFLOPS)
- Bandwidth: 576 GB/s (vs CPU ~100 GB/s)
- Speedup expectation: 5-20x for matrix-heavy operations

**When GPU Pays Off:**
- Datasets > 1MB (overhead of GPU memory copy is amortized)
- Dense matrix operations (linear regression, NN)
- Tree-based methods: less GPU benefit (irregular memory access)

**When CPU is Fine:**
- Datasets < 100MB (as per MVP target)
- Decision trees, random forests (CPU cache-friendly)
- Model inference (single predictions, not batched)

### Design Constraint: Optional, Not Mandatory

Phase 1.5 GPU support is **optional**. Core requirement:

```
1. MVPmust work on CPU-only systems (no CUDA required to install)
2. If CUDA is available and configured, GPU acceleration is used
3. Results must be identical (within numerical precision) on CPU and GPU
4. Contracts apply to Eiffel API layer; CUDA kernels are trusted
```

### Research Question for Phase 1.5

- Can EiffelStudio call C/C++ CUDA code via external library mechanism?
- What's the performance of CUDA wrapper calls (function call overhead)?
- Does Eiffel SCOOP (concurrency) conflict with CUDA memory model?
- How to test that CPU and GPU produce identical results?

---

## Research Questions

1. **What supervised learning algorithms are most commonly used in enterprise?** Are the top 5 (linear, logistic, trees, forests, SVM) sufficient for MVP?
2. **How do other languages handle ML verification?** What formal verification techniques exist for machine learning models?
3. **What are the performance expectations?** Can Eiffel/EiffelStudio handle real-world dataset training (100MB+)?
4. **How should contracts be written for ML algorithms?** What do correctness postconditions look like when outputs are probabilistic?
5. **What preprocessing requirements exist?** How much of the pipeline should be in simple_ml vs. left to user code?
6. **How does simple_optimization compare to alternatives?** Is gradient descent implementation sufficient for all algorithms?
7. **What about numerical stability?** How to ensure IEEE 754 compliance and handle edge cases (NaN, Inf)?
8. **Should we include model serialization?** Critical for deployment or deferrable to Phase 2?
9. **What about regulatory domain requirements?** Do fintech/healthtech users need audit trails, explainability, or certification?
10. **How does this position Eiffel in the ML market?** Is the contract-verification angle strong enough for adoption?
11. **GPU Strategy (Phase 1.5):** Can Eiffel safely call CUDA via C/C++ bindings? What's the performance/complexity trade-off?
12. **How to test GPU vs CPU equivalence?** What tolerance is acceptable for numerical differences?
