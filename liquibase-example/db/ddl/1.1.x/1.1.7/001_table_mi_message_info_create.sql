CREATE TABLE `mi_message_info` (
  `mi_message_info_id` varchar(40) NOT NULL COMMENT '主键',
  `title` varchar(100) DEFAULT NULL COMMENT '消息标题',
  `content` varchar(100) DEFAULT NULL COMMENT '消息内容',
  `send_time` datetime DEFAULT NULL COMMENT '发送时间',
  `me_message_entrance_id` varchar(40) DEFAULT NULL COMMENT '消息入口表主键',
  `msg_status` varchar(100) DEFAULT NULL COMMENT '同意，拒绝，未处理',
  `msg_type` varchar(100) DEFAULT NULL COMMENT '消息种类1:文字（默认）2:图片 3：语音 ',
  `sender_scy_user_id` varchar(40) DEFAULT NULL COMMENT '消息发送者scy_user_id',
  `receiver_scy_user_id` varchar(40) DEFAULT NULL COMMENT '消息接收者scy_user_id',
  `createdby` varchar(40) NOT NULL DEFAULT '' COMMENT '新建者',
  `createdon` datetime NOT NULL COMMENT '新建日期',
  `modifiedby` varchar(40) NOT NULL DEFAULT '' COMMENT '修改者',
  `modifiedon` datetime NOT NULL COMMENT '修改日期',
  `deletion_state` char(1) NOT NULL DEFAULT '0' COMMENT '删除状态,0未删除，1已删除',
  `description` varchar(500) DEFAULT '' COMMENT '备注',
  PRIMARY KEY (`mi_message_info_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



