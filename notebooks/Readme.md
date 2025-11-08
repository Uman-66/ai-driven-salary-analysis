# 🧠 Data Science Salary Analysis Project

## 📘 Overview

This project explores **global data science salaries** by combining multiple datasets to analyze how factors like experience level, company size, remote work, and cost of living affect salaries worldwide. The dataset is enriched with GDP and cost-of-living data to enable deeper economic insights.

The project follows a structured pipeline approach with **four main phases** (so far completed: Phase 0 to Phase 3).

---

## 🏗️ Phase 0 — Project Setup

**Objective:** Initialize the environment and organize the project.

### Steps:

1. **Created folder structure:**

   ```
   data/
     raw/
     cleaned/
     processed/
   notebooks/
   scripts/
   ```
2. Installed dependencies: `pandas`, `numpy`, `matplotlib`, `seaborn`, `pathlib`, and others.
3. Verified environment and Python interpreter (fixed environment issues when needed).

---

## 🧩 Phase 1 — Data Loading & Inspection

**Objective:** Load all datasets, inspect structure, and identify potential cleaning needs.

### Datasets Used:

* **Data Science Salaries Dataset (2024)** — Kaggle dataset with global salary data.
* **GDP Data (1973–2024)** — Annual GDP per country.
* **Cost of Living Dataset (2024)** — Cost of living, rent, and purchasing power indices.

### Steps:

1. Imported all datasets using `pandas.read_csv()`.
2. Inspected basic structure:

   ```python
   df.info()
   df.describe()
   df.head()
   ```
3. Checked for nulls, duplicates, and inconsistent column names.
4. Ensured correct data types for numerical and categorical columns.

### Outcome:

All three datasets successfully loaded and verified. Ready for cleaning.

---

## 🧹 Phase 2 — Data Cleaning & Integration

**Objective:** Clean, merge, and prepare the data for analysis.

### Steps:

1. **Renamed and standardized columns** for readability (e.g., `salary_in_usd`, `work_year`, `experience_level`).
2. **Mapped codes to readable text:**

   ```python
   exp_map = {'EN': 'Entry', 'MI': 'Mid', 'SE': 'Senior', 'EX': 'Executive'}
   cleaned['experience_level'] = cleaned['experience_level'].map(exp_map)
   ```
3. **Handled duplicates and missing values.**
4. **Merged datasets:**

   * Combined salary dataset with GDP and Cost of Living datasets by country.
5. **Reindexed the dataframe** to use the numerical count column as the index.
6. Added derived fields like `log_salary` for better normalization.

### Outcome:

A unified, clean dataset containing columns:

```
['Country', 'work_year', 'experience_level', 'employment_type',
 'job_title', 'salary_in_usd', 'remote_ratio', 'company_size',
 'Cost of Living Index', 'Rent Index', 'Local Purchasing Power Index',
 'Cost of Living Plus Rent Index', 'GDP', 'remote_type', 'log_salary']
```

Exported as → `data/cleaned/cleaned_salary_data.csv`

---

## ⚙️ Phase 3 — Feature Engineering

**Objective:** Create new meaningful features and prepare data for modeling.

### Steps:

1. **Created directory** for processed data:

   ```python
   from pathlib import Path
   Path('data/processed').mkdir(parents=True, exist_ok=True)
   ```
2. **Added/engineered new features:**

   * `log_salary` → log-transformed salary for normalization.
   * `remote_type` → categorized based on `remote_ratio`.
3. **Prepared final dataset** for modeling with encoded and numeric values (to be done in Phase 4).
4. **Exported datasets:**

   ```python
   cleaned.to_csv('data/processed/engineered_salary_data.csv', index=False)
   # df_final.to_csv('data/processed/model_ready_salary_data.csv', index=False)
   ```
5. Verified export success and structure.

### Outcome:

Data successfully transformed and saved for modeling.

---

## 🚀 Next Steps (Phase 4)

**Goal:** Model training and evaluation.

* Encode categorical variables.
* Split data into training and testing sets.
* Build predictive models (e.g., Linear Regression, Random Forest).
* Evaluate with RMSE, R², and visualizations.

---

## 📁 Folder Summary

```
project_root/
├── data/
│   ├── raw/                  # Original datasets
│   ├── cleaned/              # Cleaned merged data
│   └── processed/            # Feature-engineered data
├── notebooks/                # Jupyter notebooks per phase
├── scripts/                  # Python scripts for automation
└── README.md                 # Documentation
```

---

## ✅ Current Progress Summary

| Phase | Status  | Description                              |
| ----- | ------- | ---------------------------------------- |
| 0     | ✅ Done  | Environment setup and structure creation |
| 1     | ✅ Done  | Data loading and inspection              |
| 2     | ✅ Done  | Data cleaning and integration            |
| 3     | ✅ Done  | Feature engineering and export           |
| 4     | 🔜 Next | Modeling and evaluation                  |

---

## 📦 Outputs So Far

* **Cleaned Dataset:** `data/cleaned/cleaned_salary_data.csv`
* **Processed Dataset:** `data/processed/engineered_salary_data.csv`

---

## 🧭 Notes

* Keep Jupyter notebooks versioned per phase.
* Use Git commits after completing each phase.
* Maintain consistent naming conventions for all exports.

---

*End of Phase 3 — Data Prepared for Modeling.*
## Phase 4: Exploratory Data Analysis (EDA)

### Objective

The goal of Phase 4 was to perform an in-depth exploratory data analysis to understand patterns, trends, and relationships within the cleaned and feature-engineered dataset. This step transforms data from raw numbers into meaningful insights that guide future modeling decisions.

### Steps Performed

#### 1. Automated EDA Report

* Used `ydata-profiling` to automatically generate a comprehensive EDA report.
* The report includes:

  * Data type summary
  * Missing value overview
  * Correlation heatmaps
  * Feature distributions
  * Outlier detection
* Exported the report as an HTML file to `/reports/eda_report.html`.

#### 2. Manual EDA and Visualization

* Conducted focused analyses to explore specific relationships.
* Key plots and analyses performed:

  * **Salary Distribution:** Visualized salary spread and central tendency.
  * **Experience Level vs Salary:** Analyzed how experience affects salary growth.
  * **Country-wise Salary Comparison:** Highlighted top-paying regions.
  * **Remote Ratio Impact:** Compared remote, hybrid, and on-site salaries.
  * **AI-related Roles:** Checked salary differences between AI-focused and other tech roles.
  * **Economic Indicators:** Studied the influence of GDP and Cost of Living on salary levels.

#### 3. Insights Derived

* **AI-skilled developers** consistently earn more than non-AI roles.
* **Remote work** correlates with slightly higher salaries, especially in developed economies.
* **Experience level** remains the strongest determinant of compensation.
* **Cost of living and GDP** both show moderate correlation with salary but vary by region.

#### 4. Outputs Generated

* Visual plots stored in `/visuals/` directory.
* Full automated EDA report saved in `/reports/eda_report.html`.
* Summary of insights included within the Jupyter notebook for documentation.

### Tools and Libraries Used

* `pandas`, `numpy` for data manipulation.
* `matplotlib`, `seaborn`, `plotly` for visualization.
* `ydata-profiling` for automated EDA.


## 🚀 Phase 5 — SQL Integration & Data Exploration

In this phase, we connected our cleaned and feature-engineered salary dataset to an **SQLite database** for structured querying and analysis within the same Jupyter Notebook.

This allows us to use the power of **SQL queries** alongside Python’s **pandas** for data exploration, insights extraction, and validation.

---

### 🧩 Objectives

* Load processed data (`engineered_salary_data.csv` and `model_ready_salary_data.csv`) into an SQLite database.
* Execute SQL queries directly within the notebook to explore relationships and patterns.
* Compare salary distributions, experience levels, and company attributes using SQL aggregate functions.
* Learn how categorical encoding affects query structure.

---

### ⚙️ Steps Performed

#### 1. **Setup SQLite Connection**

We used the built-in `sqlite3` library to create a connection and cursor:

```python
import sqlite3
conn = sqlite3.connect("data/salary_analysis.db")
```

#### 2. **Load Data into Database**

We uploaded both datasets to separate SQL tables for flexibility:

```python
import pandas as pd

df_eng = pd.read_csv("data/processed/engineered_salary_data.csv")
df_final = pd.read_csv("data/processed/model_ready_salary_data.csv")

df_eng.to_sql("salary_data", conn, if_exists="replace", index=False)
df_final.to_sql("salary_data_numeric", conn, if_exists="replace", index=False)
```

---

#### 3. **Run SQL Queries in Python**

Example query using the categorical dataset:

```python
query = """
SELECT experience_level, AVG(salary_in_usd) AS avg_salary
FROM salary_data
GROUP BY experience_level
ORDER BY avg_salary DESC;
"""
pd.read_sql(query, conn)
```

If you use the numeric (encoded) dataset instead, you must adapt queries since the `experience_level` column was one-hot encoded:

```python
query = """
SELECT 
    AVG(CASE WHEN experience_level_SE = 1 THEN salary_in_usd END) AS SE_avg,
    AVG(CASE WHEN experience_level_MI = 1 THEN salary_in_usd END) AS MI_avg,
    AVG(CASE WHEN experience_level_EN = 1 THEN salary_in_usd END) AS EN_avg,
    AVG(CASE WHEN experience_level_EX = 1 THEN salary_in_usd END) AS EX_avg
FROM salary_data_numeric;
"""
pd.read_sql(query, conn)
```

---

#### 4. **Key Learnings**

* SQL provides fast, readable summaries and group analyses.
* When categorical variables are one-hot encoded, queries must reference new binary column names.
* Using SQLite within Jupyter bridges the gap between raw Python analysis and database-driven workflows.

---

### 📂 Outputs

* Database file: `data/salary_analysis.db`
* SQL Tables:

  * `salary_data` → categorical dataset for exploration
  * `salary_data_numeric` → numeric dataset for modeling

---

### 🧠 Next Phase (Phase 6)

We’ll visualize the SQL-driven insights with **Matplotlib, Seaborn, and Plotly**, transforming query outputs into interactive charts and dashboards.

---

