
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 1284; }

// ���������촦��
void create()
{
        set_name("�����");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(60);
        set_value(4500);
        set_max_lasting(12899);
        set("ap", 0);
        set("dp", 150);
        set("cp", 0);
        set("pp", 98);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�����";
}
