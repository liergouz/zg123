
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit ARMOR;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1224; }

// ���������촦��
void create()
{
        set_name("��ˮ��װ");
        set_picid_1(6078);
        set_picid_2(6078);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 81);
        set("cp", 0);
        set("pp", 51);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ˮ��װ";
}
