DROP TABLE IF EXISTS `dynamic_func`;
CREATE TABLE `dynamic_func` (
  `dynamic_func_id` varchar(40) NOT NULL COMMENT '主键',
  `dynamic_func_type` varchar(40) NOT NULL COMMENT '功能类型（如：动态首页，动态个人中心等）',
  `func_sort` varchar(2048) NOT NULL COMMENT '功能列表的排序',
  `need_publish` char(1) NOT NULL COMMENT '此功能是否与已发布的功能一致',
  `createdby` varchar(40) NOT NULL DEFAULT '' COMMENT '创建者',
  `createdon` datetime NOT NULL COMMENT '创建时间',
  `modifiedby` varchar(40) NOT NULL DEFAULT '' COMMENT '修改者',
  `modifiedon` datetime NOT NULL COMMENT '最后修改时间',
  `deletion_state` char(1) NOT NULL DEFAULT '0' COMMENT '删除状态',
  `description` varchar(500) DEFAULT '' COMMENT '备注',
  PRIMARY KEY (`dynamic_func_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

