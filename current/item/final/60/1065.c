
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 1; }

// ��������Ʒ���
int get_fin_type() { return 2159; }

// ���������촦��
void create()
{
        set_name("��˿��");
        set_picid_1(6038);
        set_picid_2(6038);

        set_level(65);
        set_value(8500);
        set_max_lasting(21899);
        set("ap", 0);
        set("dp", 160);
        set("cp", 0);
        set("pp", 95);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˿��";
}
