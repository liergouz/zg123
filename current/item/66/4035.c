
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("ˮ��ͷ��");
        set_picid_1(6603);
        set_picid_2(6603);

        set_level(35);
        set_value(7500);
        set_max_lasting(6399);
        set("dp", 33);
        set("pp", 24);

        setup();

        set_gender(2);
        set_head_code(52);
}

// ��������ȡ����
string get_desc()
{
        return "ˮ��ͷ��";
}
