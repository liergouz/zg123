
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 3; }

// ��������Ʒ���
int get_fin_type() { return 2160; }

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
        set("dp", 165);
        set("cp", 0);
        set("pp", 92);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˿��";
}
