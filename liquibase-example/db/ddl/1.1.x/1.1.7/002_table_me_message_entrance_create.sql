CREATE TABLE `me_message_entrance` (
  `me_message_entrance_id` varchar(40) NOT NULL COMMENT '主键',
  `me_message_entrance_parent_id` varchar(40) DEFAULT NULL COMMENT '父级入口记录主键',
  `name` varchar(100) NOT NULL COMMENT '入口名称',
  `icon` varchar(200) DEFAULT NULL COMMENT '入口图标',
  `type` varchar(50) NOT NULL COMMENT '入口类型：1.单聊，2：群聊，3：讨论组，4：系统-讨论组，5,：系统-好友',
  `createdby` varchar(40) NOT NULL DEFAULT '' COMMENT '新建者',
  `createdon` datetime NOT NULL COMMENT '新建日期',
  `modifiedby` varchar(40) NOT NULL DEFAULT '' COMMENT '修改者',
  `modifiedon` datetime NOT NULL COMMENT '修改日期',
  `deletion_state` char(1) NOT NULL DEFAULT '0' COMMENT '删除状态,0未删除，1已删除',
  `description` varchar(500) DEFAULT '' COMMENT '备注',
  PRIMARY KEY (`me_message_entrance_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



