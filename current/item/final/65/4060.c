
// �Զ����ɣ�/make/weapon/make72b

#include <equip.h>
#include <level.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ��������Ʒ���
int get_fin_type() { return 1296; }

// ���������촦��
void create()
{
        set_name("��˿ͷ��");
        set_picid_1(6615);
        set_picid_2(6615);

        set_level(60);
        set_value(5000);
        set_max_lasting(13899);
        set("ap", 0);
        set("dp", 95);
        set("cp", 0);
        set("pp", 44);
        set("sp", 0);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��˿ͷ��";
}
