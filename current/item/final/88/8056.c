
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 8; }

// ��������Ʒ���
int get_fin_type() { return 2341; }

// ���������촦��
void create()
{
        set_name("����Ь");
        set_picid_1(8808);
        set_picid_2(8808);

        set_level(56);
        set_value(1000);
        set_max_lasting(16899);
        set("ap", 0);
        set("dp", 25);
        set("cp", 0);
        set("pp", 0);
        set("sp", 30);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "����Ь";
}
