/*
* Copyright (c) 2016 Politecnico di Milano, Inc.  All rights reserved.
* $COPYRIGHT$
* 
* Additional copyrights may follow
* 
* $HEADER$
*
*/

#ifndef ORTE_MCA_MIG_H
#define	ORTE_MCA_MIG_H

#include "orte_config.h"
#include "orte/runtime/orte_globals.h"
#include "orte/mca/mig/mig_types.h"

BEGIN_C_DECLS

/*
 * MIG module
 */

/* Function pointers*/

/* Initialize the module */
typedef int (*orte_mig_base_module_init_fn_t)(void);

/**
 * Start process migration.
 */
typedef int (*orte_mig_base_module_migrate_fn_t)(orte_job_t *jdata,
                                                  orte_node_t *src,
                                                  orte_node_t *dest);


/**
 *  Finalize the module
 */
typedef int (*orte_mig_base_module_finalize_fn_t)(void);

/**
 * MIG module structure
 */
struct orte_mig_base_module_2_0_0_t {
    /** Initialization function pointer */
    orte_mig_base_module_init_fn_t          init;
    /** Migration function pointer */
    orte_mig_base_module_migrate_fn_t      migrate;
    /** Finalize function pointer */
    orte_mig_base_module_finalize_fn_t      finalize;
    /** State of the active module, may be needed*/
    orte_mig_migration_state_t state;
};
/** Convenience typedef */
typedef struct orte_mig_base_module_2_0_0_t orte_mig_base_module_2_0_0_t;
/** Convenience typedef */
typedef orte_mig_base_module_2_0_0_t orte_mig_base_module_t;

/*
 * MIG component
 */

/**
 * Component initialization / selection
 */

struct orte_mig_base_component_2_0_0_t {
    /** Base MCA structure */
    mca_base_component_t base_version;
    /** Base MCA data */
    mca_base_component_data_t base_data;
};
/** Convenience typedef */
typedef struct orte_mig_base_component_2_0_0_t orte_mig_base_component_2_0_0_t;
/** Convenience typedef */
typedef orte_mig_base_component_2_0_0_t orte_mig_base_component_t;


#define ORTE_MIG_BASE_VERSION_2_0_0 \
  MCA_BASE_VERSION_2_0_0, \
  "mig", 2, 0, 0

        
END_C_DECLS

#endif	/* MIG_H */

