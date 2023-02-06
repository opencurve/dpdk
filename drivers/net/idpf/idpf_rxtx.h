/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2022 Intel Corporation
 */

#ifndef _IDPF_RXTX_H_
#define _IDPF_RXTX_H_

#include <idpf_common_rxtx.h>
#include "idpf_ethdev.h"

/* In QLEN must be whole number of 32 descriptors. */
#define IDPF_ALIGN_RING_DESC	32
#define IDPF_MIN_RING_DESC	32
#define IDPF_MAX_RING_DESC	4096
#define IDPF_DMA_MEM_ALIGN	4096
/* Base address of the HW descriptor ring should be 128B aligned. */
#define IDPF_RING_BASE_ALIGN	128

#define IDPF_DEFAULT_RX_FREE_THRESH	32

/* used for Vector PMD */
#define IDPF_VPMD_RX_MAX_BURST	32
#define IDPF_VPMD_TX_MAX_BURST	32
#define IDPF_VPMD_DESCS_PER_LOOP	4
#define IDPF_RXQ_REARM_THRESH	64

#define IDPF_DEFAULT_TX_RS_THRESH	32
#define IDPF_DEFAULT_TX_FREE_THRESH	32

struct idpf_tx_vec_entry {
	struct rte_mbuf *mbuf;
};

int idpf_rx_queue_setup(struct rte_eth_dev *dev, uint16_t queue_idx,
			uint16_t nb_desc, unsigned int socket_id,
			const struct rte_eth_rxconf *rx_conf,
			struct rte_mempool *mp);
int idpf_singleq_tx_vec_setup_avx512(struct idpf_tx_queue *txq);
int idpf_rx_queue_init(struct rte_eth_dev *dev, uint16_t rx_queue_id);
int idpf_rx_queue_start(struct rte_eth_dev *dev, uint16_t rx_queue_id);
int idpf_rx_queue_stop(struct rte_eth_dev *dev, uint16_t rx_queue_id);
void idpf_dev_rx_queue_release(struct rte_eth_dev *dev, uint16_t qid);

int idpf_tx_queue_setup(struct rte_eth_dev *dev, uint16_t queue_idx,
			uint16_t nb_desc, unsigned int socket_id,
			const struct rte_eth_txconf *tx_conf);
int idpf_singleq_rx_vec_setup(struct idpf_rx_queue *rxq);
int idpf_tx_queue_init(struct rte_eth_dev *dev, uint16_t tx_queue_id);
int idpf_tx_queue_start(struct rte_eth_dev *dev, uint16_t tx_queue_id);
int idpf_tx_queue_stop(struct rte_eth_dev *dev, uint16_t tx_queue_id);
void idpf_dev_tx_queue_release(struct rte_eth_dev *dev, uint16_t qid);
uint16_t idpf_singleq_recv_pkts_avx512(void *rx_queue, struct rte_mbuf **rx_pkts,
				       uint16_t nb_pkts);
uint16_t idpf_singleq_xmit_pkts_avx512(void *tx_queue, struct rte_mbuf **tx_pkts,
				       uint16_t nb_pkts);

void idpf_stop_queues(struct rte_eth_dev *dev);

void idpf_set_rx_function(struct rte_eth_dev *dev);
void idpf_set_tx_function(struct rte_eth_dev *dev);

#endif /* _IDPF_RXTX_H_ */
