
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit BOOTS;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1241; }

// ���������촦��
void create()
{
        set_name("��ˮѥ");
        set_picid_1(8806);
        set_picid_2(8806);

        set_level(30);
        set_value(3000);
        set_max_lasting(9099);
        set("ap", 0);
        set("dp", 13);
        set("cp", 0);
        set("pp", 0);
        set("sp", 26);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ˮѥ";
}
